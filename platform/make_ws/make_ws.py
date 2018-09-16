import os


def make_ws(ws_name, file_name):
    
    path = '/home/ubuntu/' 
    
    os.mkdir(path + ws_name)
    os.chdir(path + ws_name)
    os.mkdir(path + ws_name + '/src')
    os.system('catkin init')
    os.system('catkin build')
    os.chdir(os.getcwd() + '/src')
    os.system('catkin create pkg nodes')
    os.chdir(os.getcwd() + '/nodes')
    os.mkdir(os.getcwd() + '/src')
    os.system('catkin build')
    os.chdir(os.getcwd() + '/src')
    os.system('touch ' + file_name)


def main():

    ws_name = ' '
    file_name = ' '

    ws_name = raw_input('Enter the desired work space name: ')
    file_name = raw_input('Enter the desired file name (ex. what.cpp): ')

    make_ws(ws_name, file_name)


main()
