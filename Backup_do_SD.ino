/*
 * Cadastro e backup dos dados em um sd
 * Pedro Mesmer
 */
 
#include <SD.h>
#include <SPI.h>

File myFile;
int linhas = 10;
int colunas = 4;
char senha [linhas][colunas];

void setup() {
  Serial.begin(9600);
  SPI.begin();

  if (!SD.begin(4)) { // pino CS do SD no Digital 4
    Serial.println("SD não funcionou");
    while (1) { 
      // trava o programa! Verifique as conexões do SD e reinicie o dispositivo
    }
  } else {
    Serial.println("SD funcionando");
  }

  // Define tudo como 0
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      senha[i][j] = '0';
    }
  }
  // Se NÃO existe esse arquivo no SD, cria arquivo zerado
  if (!SD.exists("senha.txt")) {
    myFile = SD.open("senha.txt", FILE_WRITE);
    if (myFile) {
      Serial.println("Criando arquivo 'senhas.txt' zerao no SD");
      for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
          myFile.print(senha[i][j]);
        }
      }
      myFile.close();
    }
  } else { // Se existe esse arquivo, faz o backup
    myFile = SD.open("senha.txt", FILE_READ);
    if (myFile) {
      Serial.println("Salvando senhas do SD no programa");
      for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
          senha[i][j] = myFile.read();
        }
      }
      myFile.close();
    }
  }

}

void loop() {
  
}
