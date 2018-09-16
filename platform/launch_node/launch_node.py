import os
import rosgraph


def launch(ws_name, node_name):
	os.chdir('/home/ubuntu/' + ws_name)
	os.system('catkin build')
	os.system('rosrun nodes ' + node_name)


def main():

	if rosgraph.is_master_online():
		print('\nROS Master is Online....')
	else:
		print('\nROS Mater is Offline, please execute the (roscore) command....')
		quit()

	s = raw_input('\nDid you remember to run (source devel/setup.bash) \ncommand, in your work space base folder, in this shell [Y/N]? ')
	if s == 'n' or s == 'N':
		print('Then please do it and run the program again!!')
		quit()
	else:
		print('Good job you remembered it')


	ws_name = raw_input('Enter the work space name: ')
	node_name = raw_input('Enter the node name: ')

	launch(ws_name, node_name)


main()
