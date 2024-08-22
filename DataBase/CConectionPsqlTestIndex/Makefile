instalubuntu:
	sudo apt-get update -y
	sudo apt-get install libpq-dev -y
	echo installed

select:
	gcc Select.c -o Select.out -L/usr/include/postgresql/* -I/usr/include/postgresql -lpq
	echo done

insert:
	gcc Insert.c -o Insert.out -L/usr/include/postgresql/* -I/usr/include/postgresql -lpq
	echo done