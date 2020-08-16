# arduino-backup-SD

Verificação do módulo SD, criação do arquivo (caso não exista), e Backup de suas informações para uma variável do programa.

Com essas funções no ``` setup() ``` do arduino, fica garantido que as informações do SD estarão funcionando perfeitamente, e, caso o SD seja novo, o arquivo será criado e seu código será inciado como novo (levando em consigeração que os arquivos existentes influenciem na lógica).

## Montagem

No exemplo, o pino CS foi ligado no **pino digital 4**, os demais são padrão da conexão SPI.

## Funções

No exemplo, usei o arquivo ``` senha.txt ```, na raiz do SD.

E para o backup, foi usada uma matriz de char 10x4, **10 linhas, com 4 caracteres cada**, onde as senhas serão armazenadas. Caso precise de mais senhas, ou mais caracteres por senha, basta alterar as variáveis **linhas** e **colunas**.


Boa sorte! 
