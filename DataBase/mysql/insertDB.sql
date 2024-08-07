-- Inserções para a tabela Autor
INSERT INTO BibliotecaBase.Autor (nome, descricao) VALUES
('Autor 1', 'Descrição do Autor 1'),
('Autor 2', 'Descrição do Autor 2'),
('Autor 3', 'Descrição do Autor 3'),
('Autor 4', 'Descrição do Autor 4'),
('Autor 5', 'Descrição do Autor 5'),
('Autor 6', 'Descrição do Autor 6'),
('Autor 7', 'Descrição do Autor 7'),
('Autor 8', 'Descrição do Autor 8'),
('Autor 9', 'Descrição do Autor 9'),
('Autor 10', 'Descrição do Autor 10');

-- Inserções para a tabela Editora
INSERT INTO BibliotecaBase.Editora (nome, descricao) VALUES
('Editora 1', 'Descrição da Editora 1'),
('Editora 2', 'Descrição da Editora 2'),
('Editora 3', 'Descrição da Editora 3'),
('Editora 4', 'Descrição da Editora 4'),
('Editora 5', 'Descrição da Editora 5'),
('Editora 6', 'Descrição da Editora 6'),
('Editora 7', 'Descrição da Editora 7'),
('Editora 8', 'Descrição da Editora 8'),
('Editora 9', 'Descrição da Editora 9'),
('Editora 10', 'Descrição da Editora 10');

-- Inserções para a tabela Livro
INSERT INTO BibliotecaBase.Livro (ideditora_fk, idautor_fk, preco, desconto, nome, descricao) VALUES
('1', '1', '30', '0.5', 'Livro 1', 'Descrição do Livro 1'),
('2', '2', '25', '0.3', 'Livro 2', 'Descrição do Livro 2'),
('3', '3', '20', '0.2', 'Livro 3', 'Descrição do Livro 3'),
('4', '4', '35', '0.6', 'Livro 4', 'Descrição do Livro 4'),
('5', '5', '40', '0.7', 'Livro 5', 'Descrição do Livro 5'),
('6', '6', '30', '0.4', 'Livro 6', 'Descrição do Livro 6'),
('7', '7', '28', '0.3', 'Livro 7', 'Descrição do Livro 7'),
('8', '8', '32', '0.5', 'Livro 8', 'Descrição do Livro 8'),
('9', '9', '27', '0.2', 'Livro 9', 'Descrição do Livro 9'),
('10', '10', '22', '0.1', 'Livro 10', 'Descrição do Livro 10');

-- Inserções para a tabela Categoria
INSERT INTO BibliotecaBase.Categoria (nome) VALUES
('Categoria 1'),
('Categoria 2'),
('Categoria 3'),
('Categoria 4'),
('Categoria 5'),
('Categoria 6'),
('Categoria 7'),
('Categoria 8'),
('Categoria 9'),
('Categoria 10');

-- Inserções para a tabela Usuario
INSERT INTO BibliotecaBase.Usuario (email, senha, cpf, nome) VALUES
('email1@teste.com', 'senha1', '12345678901', 'Usuario 1'),
('email2@teste.com', 'senha2', '12345678102', 'Usuario 2'),
('email3@teste.com', 'senha3', '12345679103', 'Usuario 3'),
('email4@teste.com', 'senha4', '12345689104', 'Usuario 4'),
('email5@teste.com', 'senha5', '12345789105', 'Usuario 5'),
('email6@teste.com', 'senha6', '12346789106', 'Usuario 6'),
('email7@teste.com', 'senha7', '12456789107', 'Usuario 7'),
('email8@teste.com', 'senha8', '13456789108', 'Usuario 8'),
('email9@teste.com', 'senha9', '13456789109', 'Usuario 9'),
('email10@teste.com', 'senha10', '13456789110', 'Usuario 10');

-- Inserções para a tabela Biblioteca
INSERT INTO BibliotecaBase.Biblioteca (idusuario_fk, idlivro_fk, valorcompra) VALUES
('1', '1', '2'),
('2', '2', '3'),
('3', '3', '6'),
('4', '4', '1'),
('5', '5', '2'),
('6', '6',  '2'),
('7', '7', '3'),
('8', '8', '4'),
('9', '9', '7'),
('10', '10', '10');

-- Inserções para a tabela Gerente
INSERT INTO BibliotecaBase.Gerente (idusuario_fk) VALUES
('1'),
('2'),
('3'),
('4'),
('5'),
('6'),
('7'),
('8'),
('9'),
('10');