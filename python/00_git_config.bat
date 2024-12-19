@echo off
REM Este script configura o git

set GITHUB_NAME= alunoUFU
set GITHUB_EMAIL= alunoufu@ufu.br

REM Configura as informacoes no Git
git config --global user.name "%GITHUB_NAME%"
git config --global user.email "%GITHUB_EMAIL%"

echo Configuracoes do Git atualizadas:
echo Nome:  %GITHUB_NAME%
echo Email: %GITHUB_EMAIL%
