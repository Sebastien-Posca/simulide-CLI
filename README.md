# simulide-CLI

* Pour lancer une simulation : <br />
`./simulie --simu pathToSimu --hex pathToHex` avec l'option `--platform offscreen` pour lancer sans écran. <br />
Les logs de la simulation sont sauvegardés automatiquement sous forme de fichier json quand le programme est fermé avec `CTRL+C`.

* Pour comparer les logs de deux exécutions : <br /> `./simulide --logs pathToLogs1 pathToLogs2 margin --platform offscreen`

* Pour rejouer une simulation antérieure en se basant sur les logs : <br /> `./simulide --simu pathToSimu --play pathToLogs` 
