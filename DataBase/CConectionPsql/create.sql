--! PSQL

--* drop if exist
DROP DATABASE IF EXISTS test_index;

--* create the database
CREATE DATABASE test_index;

--* table to index
CREATE TABLE films (
	id SERIAL PRIMARY KEY,
	title VARCHAR(30),
	duration TIME,
	score VARCHAR(1),
	release_date DATE
);

--* table insert
INSERT INTO films (title, duration, score, release_date)
values ('test 1', '01:30:00', '1', TO_DATE('17/12/2016', 'DD/MM/YYYY'));