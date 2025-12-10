# setupForPrometheus

## Site oficial:

https://prometheus.io/

## Github:

https://github.com/prometheus/prometheus

## Dockerhub:

https://hub.docker.com/r/prom/prometheus/

## Atualizar permissoes

```shell
sudo chmod -R 775 prometheus prometheus_data
```

## Acesso

[aqui](http://127.0.0.1:9090/)

## Gerar config com envsubst

```shell
sudo apt install gettext-base
export $(grep -v '^#' .env | xargs)
envsubst < alertmanager/alertmanager.yml.template > alertmanager/alertmanager.yml
```