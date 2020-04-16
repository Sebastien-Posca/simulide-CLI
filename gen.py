import json

HIGH='HIGH'
LOW='LOW'

def genDigitalWrite(pin, value):
    return 'digitalWrite(%s, %s);' % (pin, value)


def genDelay(delay):
    return 'delay(%s);' % delay

def genOut(pin):
    return 'pinMode(%s, OUTPUT);' % pin


def gen(f):
    array = json.load(f)
    delay = 0
    port = 0
    x = set([])
    print('void setup() {')
    for elem in array:
        port = int(elem['port'][-1])
        if  elem['port'][-2] == "D" :
            x.add(port)
        elif  elem['port'][-2] == "B" :
            x.add(port+8)
    for e in x:
        print(genOut(e))
    print('}')
    print('void loop() {')
    for elem in array:
        delay = int(elem['time']) - delay
        state =  HIGH if elem['value'] == 1 else LOW
        print(genDelay(delay))
        port = int(elem['port'][-1])
        if  elem['port'][-2] == "D" :
            print(genDigitalWrite(port, state))
        elif  elem['port'][-2] == "B" :
            print(genDigitalWrite(port+8, state))
        print()
    print('}')
with open('out.json') as f:
    gen(f)


    