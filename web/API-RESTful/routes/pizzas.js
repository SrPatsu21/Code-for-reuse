const express = require('express');
const router = express.Router();

let pizzas = [];
let idCounter = 1;

/**
 * @swagger
 * /pizzas:
 *   get:
 *     summary: Listar todas as pizzas com filtros e paginação
 *     description: Retorna uma lista de pizzas filtradas por nome, tamanho e preço, com paginação e ordenação.
 *     parameters:
 *       - name: nome
 *         in: query
 *         description: Filtro pelo nome da pizza
 *         schema:
 *           type: string
 *       - name: tamanho
 *         in: query
 *         description: Filtro pelo tamanho da pizza
 *         schema:
 *           type: string
 *       - name: precoMin
 *         in: query
 *         description: Filtro pelo preço mínimo da pizza
 *         schema:
 *           type: number
 *       - name: precoMax
 *         in: query
 *         description: Filtro pelo preço máximo da pizza
 *         schema:
 *           type: number
 *       - name: sort
 *         in: query
 *         description: Ordenação dos resultados
 *         schema:
 *           type: string
 *           default: 'id'
 *       - name: order
 *         in: query
 *         description: Ordenação crescente ou decrescente
 *         schema:
 *           type: string
 *           default: 'asc'
 *       - name: page
 *         in: query
 *         description: Número da página para paginação
 *         schema:
 *           type: integer
 *           default: 1
 *       - name: limit
 *         in: query
 *         description: Limite de resultados por página
 *         schema:
 *           type: integer
 *           default: 10
 *     responses:
 *       200:
 *         description: Lista de pizzas paginada e filtrada
 */
router.get('/', (req, res) => {
    let resultado = [...pizzas];
    const { nome, tamanho, precoMin, precoMax, sort = 'id', order = 'asc', page = 1, limit = 10 } = req.query;

    if (nome) resultado = resultado.filter(p => p.nome.toLowerCase().includes(nome.toLowerCase()));
    if (tamanho) resultado = resultado.filter(p => p.tamanho === tamanho);
    if (precoMin) resultado = resultado.filter(p => p.preco >= parseFloat(precoMin));
    if (precoMax) resultado = resultado.filter(p => p.preco <= parseFloat(precoMax));

    resultado.sort((a, b) => {
        if (order === 'desc') return a[sort] < b[sort] ? 1 : -1;
        return a[sort] > b[sort] ? 1 : -1;
    });

    const start = (parseInt(page) - 1) * parseInt(limit);
    const paginado = resultado.slice(start, start + parseInt(limit));

    res.json({ total: resultado.length, page: parseInt(page), limit: parseInt(limit), data: paginado });
});

/**
 * @swagger
 * /pizzas/{id}:
 *   get:
 *     summary: Buscar uma pizza pelo ID
 *     description: Retorna uma pizza específica pelo seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID da pizza
 *         required: true
 *         schema:
 *           type: integer
 *     responses:
 *       200:
 *         description: Pizza encontrada
 *       404:
 *         description: Pizza não encontrada
 */
router.get('/:id', (req, res) => {
    const pizza = pizzas.find(p => p.id === parseInt(req.params.id));
    if (!pizza) return res.status(404).json({ erro: 'Pizza não encontrada' });
    res.json(pizza);
});

/**
 * @swagger
 * /pizzas:
 *   post:
 *     summary: Criar uma nova pizza
 *     description: Cria uma nova pizza com os dados fornecidos.
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               nome:
 *                 type: string
 *                 description: Nome da pizza
 *               preco:
 *                 type: number
 *                 description: Preço da pizza
 *               tamanho:
 *                 type: string
 *                 description: Tamanho da pizza (pequeno, médio, grande)
 *             required:
 *               - nome
 *               - preco
 *               - tamanho
 *     responses:
 *       201:
 *         description: Pizza criada com sucesso
 *         content:
 *           application/json:
 *             schema:
 *               type: object
 *               properties:
 *                 id:
 *                   type: integer
 *                 nome:
 *                   type: string
 *                 preco:
 *                   type: number
 *                 tamanho:
 *                   type: string
 *                 description: Detalhes da pizza criada
 */
router.post('/', (req, res) => {
    const pizza = { id: idCounter++, ...req.body };
    pizzas.push(pizza);
    res.status(201).json(pizza);
});

/**
 * @swagger
 * /pizzas/{id}:
 *   put:
 *     summary: Atualizar uma pizza
 *     description: Atualiza todos os dados de uma pizza, dado seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID da pizza a ser atualizada
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
 *               preco:
 *                 type: number
 *               tamanho:
 *                 type: string
 *     responses:
 *       200:
 *         description: Pizza atualizada com sucesso
 *       404:
 *         description: Pizza não encontrada
 */
router.put('/:id', (req, res) => {
    const index = pizzas.findIndex(p => p.id === parseInt(req.params.id));
    if (index === -1) return res.status(404).json({ erro: 'Pizza não encontrada' });
    pizzas[index] = { id: pizzas[index].id, ...req.body };
    res.json(pizzas[index]);
});

/**
 * @swagger
 * /pizzas/{id}:
 *   patch:
 *     summary: Atualizar parcialmente uma pizza
 *     description: Atualiza apenas os dados informados de uma pizza, dado seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID da pizza a ser parcialmente atualizada
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
 *         description: Pizza atualizada parcialmente
 *       404:
 *         description: Pizza não encontrada
 */
router.patch('/:id', (req, res) => {
    const pizza = pizzas.find(p => p.id === parseInt(req.params.id));
    if (!pizza) return res.status(404).json({ erro: 'Pizza não encontrada' });
    Object.assign(pizza, req.body);
    res.json(pizza);
});

/**
 * @swagger
 * /pizzas/{id}:
 *   delete:
 *     summary: Remover uma pizza
 *     description: Remove uma pizza do sistema pelo seu ID.
 *     parameters:
 *       - name: id
 *         in: path
 *         description: ID da pizza a ser removida
 *         required: true
 *         schema:
 *           type: integer
 *     responses:
 *       204:
 *         description: Pizza removida com sucesso
 *       404:
 *         description: Pizza não encontrada
 */
router.delete('/:id', (req, res) => {
    const index = pizzas.findIndex(p => p.id === parseInt(req.params.id));
    if (index === -1) return res.status(404).json({ erro: 'Pizza não encontrada' });
    pizzas.splice(index, 1);
    res.status(204).send();
});

module.exports = router;