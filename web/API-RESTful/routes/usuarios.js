const express = require('express');
const router = express.Router();

let usuarios = [];
let idCounter = 1;

/**
 * @swagger
 * /usuarios:
 *   get:
 *     summary: Listar todos os usuários
 *     description: Retorna uma lista de todos os usuários cadastrados.
 *     responses:
 *       200:
 *         description: Lista de usuários
 */
router.get('/', (req, res) => {
    res.json(usuarios);
});

/**
 * @swagger
 * /usuarios/{id}:
 *   get:
 *     summary: Buscar um usuário pelo ID
 *     description: Retorna um usuário específico, dado o seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID do usuário
 *         required: true
 *         schema:
 *           type: integer
 *     responses:
 *       200:
 *         description: Usuário encontrado
 *       404:
 *         description: Usuário não encontrado
 */
router.get('/:id', (req, res) => {
    const usuario = usuarios.find(u => u.id === parseInt(req.params.id));
    if (!usuario) return res.status(404).json({ erro: 'Usuário não encontrado' });
    res.json(usuario);
});

/**
 * @swagger
 * /usuarios:
 *   post:
 *     summary: Criar um novo usuário
 *     description: Cria um novo usuário com os dados fornecidos.
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               nome:
 *                 type: string
 *               email:
 *                 type: string
 *             required:
 *               - nome
 *               - email
 *     responses:
 *       201:
 *         description: Usuário criado com sucesso
 */
router.post('/', (req, res) => {
    const usuario = { id: idCounter++, ...req.body };
    usuarios.push(usuario);
    res.status(201).json(usuario);
});

/**
 * @swagger
 * /usuarios/{id}:
 *   put:
 *     summary: Atualizar um usuário
 *     description: Atualiza todos os dados de um usuário, dado seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID do usuário a ser atualizado
 *         required: true
 *         schema:
 *           type: integer
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               nome:
 *                 type: string
 *               email:
 *                 type: string
 *     responses:
 *       200:
 *         description: Usuário atualizado com sucesso
 *       404:
 *         description: Usuário não encontrado
 */
router.put('/:id', (req, res) => {
    const index = usuarios.findIndex(u => u.id === parseInt(req.params.id));
    if (index === -1) return res.status(404).json({ erro: 'Usuário não encontrado' });
    usuarios[index] = { id: usuarios[index].id, ...req.body };
    res.json(usuarios[index]);
});

/**
 * @swagger
 * /usuarios/{id}:
 *   patch:
 *     summary: Atualizar parcialmente um usuário
 *     description: Atualiza apenas os dados informados de um usuário, dado seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID do usuário a ser parcialmente atualizado
 *         required: true
 *         schema:
 *           type: integer
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             additionalProperties: true
 *     responses:
 *       200:
 *         description: Usuário atualizado parcialmente
 *       404:
 *         description: Usuário não encontrado
 */
router.patch('/:id', (req, res) => {
    const usuario = usuarios.find(u => u.id === parseInt(req.params.id));
    if (!usuario) return res.status(404).json({ erro: 'Usuário não encontrado' });
    Object.assign(usuario, req.body);
    res.json(usuario);
});

/**
 * @swagger
 * /usuarios/{id}:
 *   delete:
 *     summary: Remover um usuário
 *     description: Remove um usuário do sistema pelo seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID do usuário a ser removido
 *         required: true
 *         schema:
 *           type: integer
 *     responses:
 *       204:
 *         description: Usuário removido com sucesso
 *       404:
 *         description: Usuário não encontrado
 */
router.delete('/:id', (req, res) => {
    const index = usuarios.findIndex(u => u.id === parseInt(req.params.id));
    if (index === -1) return res.status(404).json({ erro: 'Usuário não encontrado' });
    usuarios.splice(index, 1);
    res.status(204).send();
});

module.exports = router;