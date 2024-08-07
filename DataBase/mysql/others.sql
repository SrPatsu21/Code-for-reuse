-- DTL

BEGIN, COMMIT, TRANSACTION, ROLLBACK.

-- start operation
Begin;

-- save
SAVEPOINT ANYNAME;
-- more sql
-- save
SAVEPOINT POINT2;

commit;
-- ROLLBACK wont work after commit 
ROLLBACK TO SAVEPOINT POINT2;


https://retool.com/blog/isolation-levels-and-locking-in-relational-databases

Consistência ACID
CREATE TABLE test(
a INT,
b INT CHECK(a+b=100)
);

Users And Grant
https://www.strongdm.com/blog/mysql-create-user-manage-access-privileges-how-to
`ALL PRIVILEGES`: The user is granted all privileges except GRANT OPTION and PROXY.


/*criar usuario*/
CREATE USER gerente with encrypted password '123';
CREATE USER 'newuser'@'localhost' IDENTIFIED BY 'ab1238324AA#';
/*permitir*/ 
GRANT SELECT on servicoto gerente;
GRANT SELECT, INSERT ON Autor.* TO 'newuser'@'localhost';
/*revogar*/
REVOKE SELECT on servico FROM gerente;
REVOKE SELECT, INSERT ON Autor.* FROM 'newuser'@'localhost';

//alterar
ALTER USER 'newuser'@'localhost' IDENTIFIED BY 'new_password';

//delet
DROP USER 'local_user'@'localhost';

//show 
SHOW GRANTS FOR 'local_user'@'localhost';

Algebra 
Relex ->https://dbis-uibk.github.io/relax/landing



calculo relacional de tupla


calculo relacional de dominio




JOINS

(INNER) JOIN: Returns records that have matching values in both tables
LEFT (OUTER) JOIN: Returns all records from the left table, and the matched records from the right table
RIGHT (OUTER) JOIN: Returns all records from the right table, and the matched records from the left table
FULL (OUTER) JOIN: Returns all records when there is a match in either left or right table

SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate
FROM Orders
INNER JOIN Customers ON Orders.CustomerID=Customers.CustomerID;

Atividade 1, fazer em algebra e sql
1 SQL:SELECT nome-material FROM Materiall WHERE valor-unitario < 5
1 ALG:π{nome-material}(σ{valor-unitario < 5}(Material))
2 SQL:SELECT nome-fornecedor, valor-total FROM Fornecedor, Compra INNER JOIN Fornecedor ON Fornecedor.id = 2 
2 ALG:π{nome-fornecedor, valor-total}(σ{Fornecedor.id = ‘2’}(Fornecedor, Compra))
3 SQL: SELECT endereco FROM Usuario LEFT JOIN  Compra ON Compra.idusuario =  Usuario.idusuario
3 ALG:
4 SQL: SELECT quantidade FROM Compra INNER JOIN Material ON Compra.id = Material.id
4: ALG:
5 SQL: 



DDL - Data Definition Language - Linguagem de Definição de Dados.
São os comandos que interagem com os objetos do banco.
São comandos DDL : CREATE, ALTER e DROP
CREATE DATABASE BibliotecaBase;
DROP DATABASE BibliotecaBase;
CREATE TABLE BibliotecaBase.Biblioteca (
    idbiblioteca INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    idusuario_fk INT NOT NULL,
    idlivro_fk INT NOT NULL,
    paginaslidas INT,
    periodo DATE,
    valorcompra DOUBLE NOT NULL
);

ALTER TABLE BibliotecaBase.Biblioteca ADD novacoluna varchar(255);

ALTER TABLE BibliotecaBase.Biblioteca ADD CONSTRAINT FK_Biblioteca_3
    FOREIGN KEY (idlivro_fk)
    REFERENCES BibliotecaBase.Livro (idlivro);
DROP TABLE BibliotecaBase.Biblioteca
DROp DATABASE BibliotecaBase


DML - Data Manipulation Language - Linguagem de Manipulação de Dados.
São os comandos que interagem com os dados dentro das tabelas.
São comandos DML : INSERT, DELETE e UPDATE
INSERT INTO `BibliotecaBase`.`Autor` (`nome`, `descricao`) VALUES ('nome', 'descricao');
DELETE FROM BibliotecaBase.Autor WHERE BibliotecaBase.Autor.nome = ‘Pedro’;
UPDATE BibliotecaBase.Autor SET  BibliotecaBase.Autor.nome = ‘Joao’ WHERE  BibliotecaBase.Autor.id = 5;
DQL - Data Query Language - Linguagem de Consulta de dados.
São os comandos de consulta.
São comandos DQL : SELECT (é o comando de consulta)
Aqui cabe um parenteses. Em alguns livros o SELECT fica na DML em outros tem esse grupo próprio.
SELECT * FROM BibliotecaBase.Autor;
(INNER) JOIN: Returns records that have matching values in both tables
LEFT (OUTER) JOIN: Returns all records from the left table, and the matched records from the right table
RIGHT (OUTER) JOIN: Returns all records from the right table, and the matched records from the left table
FULL (OUTER) JOIN: Returns all records when there is a match in either left or right table
DTL - Data Transaction Language - Linguagem de Transação de Dados.
São os comandos para controle de transação.
São comandos DTL : BEGIN TRANSACTION, COMMIT E ROLLBACK
https://dev.mysql.com/doc/refman/8.0/en/commit.html
atomicidade, tudo ou nada
//inicia a operacao
Begin;
//fecha a transacao e garante

//save 
SAVEPOINT ANYNAME;
//more sql
//save
SAVEPOINT POINT2;

commit;
//ROLLBACK nao funciona apos ser comitado
ROLLBACK TO SAVEPOINT POINT2;
DCL - Data Control Language - Linguagem de Controle de Dados.
São os comandos para controlar a parte de segurança do banco de dados.
São comandos DCL : GRANT, REVOKE E DENY.
/*criar usuario*/
CREATE USER gerente with encrypted password '123';
CREATE USER 'newuser'@'localhost' IDENTIFIED BY 'ab1238324AA#';
/*permitir*/ 
GRANT SELECT on servicoto gerente;
GRANT SELECT, INSERT ON Autor.* TO 'newuser'@'localhost';
/*revogar*/
REVOKE SELECT on servico FROM gerente;
REVOKE SELECT, INSERT ON Autor.* FROM 'newuser'@'localhost';

//alterar
ALTER USER 'newuser'@'localhost' IDENTIFIED BY 'new_password';

//delet
DROP USER 'local_user'@'localhost';

//show 
SHOW GRANTS FOR 'local_user'@'localhost';












trigger

DROP TRIGGER IF EXISTS `BibliotecaBase`.`Livro_AFTER_INSERT`;

DELIMITER $$
USE `BibliotecaBase`$$

CREATE DEFINER=`root`@`localhost`
TRIGGER `Livro_AFTER_INSERT` AFTER INSERT
ON `Livro`
FOR EACH ROW BEGIN
    UPDATE BibliotecaBase.Livro
	SET BibliotecaBase.Livro.desconto = 2
	WHERE BibliotecaBase.Livro.idlivro = NEW.idlivro;
END$$
DELIMITER ;

INSERT INTO BibliotecaBase.Livro
(ideditora_fk, idautor_fk, preco, desconto, nome, descricao) VALUES
('2', '2', '30', '0.5', 'Livro 1', 'Descrição do Livro 1');

SELECT idlivro, desconto FROM BibliotecaBase.Livro;
