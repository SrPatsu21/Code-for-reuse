CREATE DATABASE BibliotecaBase;

BEGIN;
/* Lógico_1: */
CREATE TABLE BibliotecaBase.Livro (
    idlivro INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    ideditora_fk INT,
    idautor_fk INT,
    preco DOUBLE NOT NULL,
    desconto FLOAT,
    nome VARCHAR(64) NOT NULL,
    descricao VARCHAR(128)
);

CREATE TABLE BibliotecaBase.Usuario (
    idusuario INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    email VARCHAR(256) NOT NULL,
    senha VARCHAR(64) NOT NULL,
    cpf VARCHAR(11) NOT NULL,
    nome VARCHAR(64) NOT NULL
);

CREATE TABLE BibliotecaBase.Biblioteca (
    idbiblioteca INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    idusuario_fk INT NOT NULL,
    idlivro_fk INT NOT NULL,
    paginaslidas INT,
    periodo DATE,
    valorcompra DOUBLE NOT NULL
);

CREATE TABLE BibliotecaBase.Editora (
    ideditora INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(64) NOT NULL,
    descricao VARCHAR(128)
);

CREATE TABLE BibliotecaBase.Autor (
    idautor INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(64),
    descricao VARCHAR(128)
);

CREATE TABLE BibliotecaBase.Categorias (
    idcategorias INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    idlivro_fk INT NOT NULL,
    idcategoria_fk INT NOT NULL
);

CREATE TABLE BibliotecaBase.Categoria (
    idcategoria INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(32) NOT NULL
);

CREATE TABLE BibliotecaBase.Gerente (
    idgerent INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    idusuario_fk INT NOT NULL
);

CREATE TABLE BibliotecaBase.Alteracao (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    idusuario_fk INT NOT NULL,
    periodo DATE NOT NULL,
    tabela VARCHAR(32) NOT NULL,
    idtabelaalterada INT NOT NULL,
    motivo VARCHAR(256) NOT NULL
);

ALTER TABLE BibliotecaBase.Livro ADD CONSTRAINT FK_Livro_2
    FOREIGN KEY (ideditora_fk)
    REFERENCES BibliotecaBase.Editora (ideditora);

ALTER TABLE BibliotecaBase.Livro ADD CONSTRAINT FK_Livro_3
    FOREIGN KEY (idautor_fk)
    REFERENCES BibliotecaBase.Autor (idautor);

ALTER TABLE BibliotecaBase.Biblioteca ADD CONSTRAINT FK_Biblioteca_2
    FOREIGN KEY (idusuario_fk)
    REFERENCES BibliotecaBase.Usuario (idusuario);

ALTER TABLE BibliotecaBase.Biblioteca ADD CONSTRAINT FK_Biblioteca_3
    FOREIGN KEY (idlivro_fk)
    REFERENCES BibliotecaBase.Livro (idlivro);

ALTER TABLE BibliotecaBase.Categorias ADD CONSTRAINT FK_Categorias_2
    FOREIGN KEY (idlivro_fk)
    REFERENCES BibliotecaBase.Livro (idlivro);

ALTER TABLE BibliotecaBase.Categorias ADD CONSTRAINT FK_Categorias_3
    FOREIGN KEY (idcategoria_fk)
    REFERENCES BibliotecaBase.Categoria (idcategoria);

ALTER TABLE BibliotecaBase.Gerente ADD CONSTRAINT FK_Gerente_2
    FOREIGN KEY (idusuario_fk)
    REFERENCES BibliotecaBase.Usuario (idusuario);

COMMIT;