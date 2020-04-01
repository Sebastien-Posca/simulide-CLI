/***************************************************************************
 *   Copyright (C) 2012 by santiago González                               *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#include <QDomDocument>

#include "connector.h"
#include "chip.h"
#include "utils.h"
#include "pin.h"
#include "simuapi_apppath.h"


Chip::Chip( QObject* parent, QString type, QString id )
    : Component( parent, type, id )
    , eElement( id.toStdString() )
{
    m_numpins = 0;
}
Chip::~Chip() {}

void Chip::initChip()
{
    QFile file( m_dataFile );
    if( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        MessageBoxNB( "Chip::initChip",
                  tr("Cannot read file:\n%1:\n%2.").arg(m_dataFile).arg(file.errorString()) );
          m_error = 1;
          return;
    }

    QDomDocument domDoc;
    if( !domDoc.setContent(&file) )
    {
         MessageBoxNB( "Chip::initChip",
                   tr("Cannot set file:\n%1\nto DomDocument") .arg(m_dataFile));
         file.close();
         m_error = 2;
         return;
    }
    file.close();

    QDomElement root  = domDoc.documentElement();

    if( root.tagName()!="package" )
    {
        MessageBoxNB( "Chip::initChip",
                  tr("Error reading Chip file:\n%1\nNo valid Chip") .arg(m_dataFile));
        m_error = 3;
        return;
    }

    int width  = root.attribute( "width" ).toInt();
    int height = root.attribute( "height" ).toInt();
    m_numpins  = root.attribute( "pins" ).toInt();
    m_ePin.resize( m_numpins );
    
    if( root.attribute( "type" ) == "block" )
    {
        m_isChip = false;
        m_color = QColor( 255, 255, 255 );
    }
    else
    {
        m_isChip = true;
        m_color = QColor( 50, 50, 70 );
    }

    m_area = QRect( 0, 0, 8*width, 8*height );
    //setTransformOriginPoint( togrid( boundingRect().center()) );
    setLabelPos( m_area.x(), m_area.y()-20, 0);
    setShowId( true );

    QDomNode node = root.firstChild();

    int chipPos = 0;

    while( !node.isNull() )
    {
        QDomElement element = node.toElement();
        if( element.tagName() == "pin" )
        {
            QString type  = element.attribute( "type" );
            QString label = element.attribute( "label" );
            QString id    = element.attribute( "id" );
            QString side  = element.attribute( "side" );
            int     pos   = element.attribute( "pos" ).toInt();

            int xpos = 0;
            int ypos = 0;
            int angle = 0;

            if( side=="left" )
            {
                xpos = -8;
                ypos = 8*pos;
                angle = 180;
            }
            else if( side=="top")
            {
                xpos = 8*pos;
                ypos = -8;
                angle = 90;
            }
            else if( side=="right" )
            {
                xpos =  width*8+8;
                ypos = 8*pos;
                angle = 0;
            }
            else if( side=="bottom" )
            {
                xpos = 8*pos;
                ypos =  height*8+8;
                angle = 270;
            }
            chipPos++;
            addPin( id, type, label, chipPos, xpos, ypos, angle );
        }
        node = node.nextSibling();
    }
}

void Chip::addPin( QString id, QString type, QString label, int pos, int xpos, int ypos, int angle )
{
    Pin* pin = new Pin( angle, QPoint(xpos, ypos), m_id+"-"+id, pos-1, this ); // pos in package starts at 1
    pin->setLabelText( label );
    
    if     ( type == "inverted" ) pin->setInverted( true );
    else if( type == "unused" )   pin->setUnused( true );
    else if( type == "null" )
    {
        pin->setVisible( false );
        pin->setLabelText( "" );
    }
    
    if( !m_isChip ) pin->setLabelColor( QColor( 0, 0, 0 ) );

    m_ePin[pos-1] = pin;
}

void Chip::remove()
{
    for( uint i=0; i<m_ePin.size(); i++ )
    {
        Pin* pin = static_cast<Pin*>(m_ePin[i]);
        if( pin->connector() ) pin->connector()->remove();
    }
    Component::remove();
}

void Chip::contextMenuEvent( QGraphicsSceneContextMenuEvent* event )
{
    event->accept();
    QMenu *menu = new QMenu();
    /*QAction *loadAction = menu->addAction( QIcon(":/fileopen.png"),tr("Load firmware") );
    connect( loadAction, SIGNAL(triggered()), this, SLOT(slotLoad()) );

    QAction *reloadAction = menu->addAction( QIcon(":/fileopen.png"),tr("Reload firmware") );
    connect( reloadAction, SIGNAL(triggered()), this, SLOT(slotReload()) );*/

    menu->addSeparator();

    Component::contextMenu( event, menu );
    menu->deleteLater();
}

void Chip::paint( QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    Component::paint( p, option, widget );

    p->drawRoundedRect( m_area, 1, 1);

    if( m_isChip )
    {
        p->setPen( QColor( 170, 170, 150 ) );
        p->drawArc( boundingRect().width()/2-6, -4, 8, 8, 0, -2880 /* -16*180 */ );
    }
}

#include "moc_chip.cpp"

