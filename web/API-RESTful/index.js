const express = require('express');
const app = express();
const port = 3000;

const swaggerUi = require('swagger-ui-express');
const swaggerJsdoc = require('swagger-jsdoc');

app.use(express.json());

const usuariosRouter = require('./routes/usuarios');
const pizzasRouter = require('./routes/pizzas');

// Definindo as opções do Swagger
const swaggerOptions = {
    swaggerDefinition: {
        openapi: '3.0.0',
        info: {
        title: 'API da Pizzaria',
        version: '1.0.0',
        description: 'Documentação gerada automaticamente com Swagger JSDoc',
        },
        host: 'localhost:3000',
        schemes: ['http'],
    },
    apis: ['./routes/*.js'], // Caminho para os arquivos de rota onde os comentários estarão
};

// Gerando a documentação Swagger
const swaggerSpec = swaggerJsdoc(swaggerOptions);

// Rota para exibir a documentação
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerSpec));

app.use('/usuarios', usuariosRouter);
app.use('/pizzas', pizzasRouter);

app.listen(port, () => {
    console.log(`API da pizzaria rodando em http://localhost:${port}`);
    console.log(`Documentação Swagger disponível em http://localhost:${port}/api-docs`);
});
