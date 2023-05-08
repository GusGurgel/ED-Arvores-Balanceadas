## Pontos do projeto:

1. Temos que ler um arquivo CSV. Portanto, vai ser necessário usar bibliotecas que manipulem arquivos.
	* [Video do Juds \(Arquivos\)](https://www.youtube.com/live/qveu-Iv6Tpk?feature=share)

1. O arquivo tem que ser carregado e dentro dele vai ter um conjunto de informções sobre pessoas dividida da seguinte forma e order: 
	1. CPF (Numério)
	1. Primeiro nome (String)
	1. Sobrenome (String)
	1. Data de nascimento no formato MM/DD/AAAA
	1. Nome da cidade onde nasceu (string)

1. O campo de cada registro é dividido por víruglas (,) da seguinte forma:
	* 388.624.732-57,Tiago,Cunha,7/19/1989,Rio Branco

1. Vai ter que carregar em classes do tipo pessoa


## Consultas que o programa deve fazer

* Consultar uma única pessoa pelo seu PDF e exibir na tela seus dados.
* Consultar todas as pessoas cujo primeiro nome comece um uma string informada pelo usuário e imprimir em forma de lista todas essas pessoas na tela
	* Importante perceber que ele vai passar um sufixo, não a string completa.
* Consultar todas as pessoas que nasceram em um intervalo estabelecido pelo usuário e imprimir em forma de lista na tela

## Pensamentos

Primeiramente é necessário transformar a árovre AVL em uma árovre AVL templatizada. Depois disso, temos que pensar em como cada árvore vai ser instanciada para cada atributo de pessoas.

É preciso ter 3 árvores. Uma balanceada para busca de **CPFs** (consulta 1). Outra para **nomes** (consulta 2). E por último uma para **Datas de Nascimento**.