A quantidade de threads pode ser escolhida no topo do código, para realizar os testes utilizamos 4.
O valor de PI calculado no programa sem o uso do mutex varia entre diversos valores, por exemplo: 0.00000000066666666642 e 3.14159264958921013999

As divergencias foram causadas por um problema de condição de corrida (race condition) na variável compartilhada "sum". Como cada thread atualiza a variável "sum"
simultaneamente sem sincronização, pode ocorrer uma condição de corrida em que um thread lê o valor antigo de "sum" antes que outro thread conclua a atualização. 
Isso pode levar a resultados inconsistentes, portanto, você pode obter um valor diferente para PI cada vez que executar o programa
