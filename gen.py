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
    print('void setup() {')
    for elem in array:
        port = int(elem['port'][-1])
        if  elem['port'][-2] == "D" :
            print(genOut(port))
        elif  elem['port'][-2] == "B" :
            print(genOut(port+8))
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


    