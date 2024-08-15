--! PSQL

--* drop if exist
DROP DATABASE IF EXISTS test_index;

--* create the database
CREATE DATABASE test_index;

--* table to index
CREATE TABLE films (
	title VARCHAR(30),
	duration TIME,
	score VARCHAR(1),
	release_date DATE
);