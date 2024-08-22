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

--* select used for test
EXPLAIN ANALYSE SELECT COUNT(title) FROM films WHERE (title = 'Joker');
EXPLAIN ANALYSE SELECT COUNT(title) FROM films WHERE (title LIKE 'Joke%');
EXPLAIN ANALYSE SELECT COUNT(title) FROM films WHERE (id = 1000);
--* insert used for test
EXPLAIN ANALYSE INSERT INTO films (title, duration, score, release_date)
values ('test 1', '01:30:00', '1', TO_DATE('17/12/2016', 'DD/MM/YYYY'));

--* index
DROP INDEX films_index;
	-- B-tree
	CREATE INDEX films_index ON films (title);
	-- hash
	CREATE INDEX films_index ON films USING hash (title);
	-- gin
	CREATE EXTENSION btree_gin;
	CREATE INDEX films_index ON films USING gin (title);
	-- gist
	CREATE EXTENSION btree_gist;
	CREATE INDEX films_index ON films USING gist (title);
	-- CONCURRENTLY
	CREATE INDEX CONCURRENTLY films_index ON films (title);
	-- Unique
	CREATE UNIQUE INDEX films_index ON films (id);
	ALTER TABLE films ADD CONSTRAINT primary_key UNIQUE (films_unique);
	-- Expression Index
	CREATE INDEX films_index ON films (LOWER(title));
	-- partial
	CREATE INDEX films_index ON films (title) WHERE score = '5';
	-- Block Range Index
	CREATE INDEX films_index ON films USING BRIN (release_date);
