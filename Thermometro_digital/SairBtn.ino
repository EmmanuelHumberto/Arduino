/* Se o botao for precionado irá intenromper o ciclo de petição For()
     o valor dentro switchPin irá para nivel baixo = 0V
     o pull-up mantém o pino em HIGH internamente
    */
void botaoSair() {
      running = ! running;
      digitalWrite ( LEDpin, running );
      sair();
      return;
}
