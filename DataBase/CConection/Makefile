instalubuntu:
	sudo apt-get update -y
	sudo apt-get install libpq-dev -y
	echo installed

compileconnection:
	gcc connection.c -o connection.out -L/usr/include/postgresql/* -I/usr/include/postgresql -lpq
	echo done