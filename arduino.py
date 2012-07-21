import serial

class Arduino:
    def __init__(self):
        try:
            self.serial_connection = serial.Serial('/dev/ttyACM0', 9600)
        except:
            print "Fail to connect to the port /dev/ttyACM0!"

    def send_action_to_prototype(self, action):
        self.serial_connection.write(action)
        time.sleep(1)

def menu():
    print ":: Choose the direction to control the prototype ::"
    print "f - Move the prototype to front"
    print "b - Move the prototype to back"
    print "r - Move the prototype to right"
    print "l - Move the prototype to left"
    print "s - Stop the prototype"
    print "e - Exit the program"

arduino = Arduino()
menu()
action = raw_input('Choose the direction: ')
while action != 'e':
    arduino.send_action_to_prototype(action)
    menu()
    action = raw_input('Choose the direction: ')
