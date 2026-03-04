# Strlib 

Biblioteca em **C** para manipulação de strings dinâmicas, oferece funcionalidades além da biblioteca padrão `string.h`.  
Inclui gerenciamento centralizado de memória com registro de strings e liberação baseada em *memory pool*.  
Inspirada na abordagem **Rust** de manipulação de strings.

---

## Funcionalidades

- Criação de strings dinâmicas com capacidade flexível.  
- Inicialização e atualização de strings a partir de literais (`str`) para strings temporárias na stack e String para strings alocadas na heap.   
- Comparação de strings (`string_compare`).  
- Concatenação com ajuste de capacidade (`string_concat`).  
- Substituição de caracteres **in-place**.  
- Registro e rastreamento global de String (`register_string`, `unregister_string`).  
- Função `clean_str` que libera todas as strings ao final do programa. (Ainda procuro uma forma de retirar clean_str da responsabilidade do usuário)  
- Reajuste de capacidade (`recalc_capacity`).  
- API modular e extensível, simulando orientação a objetos em C.  
- Projeto ainda em desenvolvimento, módulos (principalmente para manipulação e performance) continuarão sendo atualizados e criados 
---

## Estrutura do código fonte

```bash
include/  
  strlib.h        # Header principal da biblioteca  
  memory.h        # Funções auxiliares de alocação  
  display.h       # Funções de debug/erro

src/  
  strlib.c        # Implementação das funções de criação e manipulação da heap
  memory.c        # verificação de ponteiros e alocação  
  registry.c      # Registro global de strings e "garbage collector"  
```

---

## Structs

As definições abaixo podem ser usadas fora dos módulos da biblioteca, contanto que `strlib.h` esteja incluído:

```c
typedef const char* str;     // String imutável  
typedef char* mut_str;       // String mutável  

typedef struct String {  
    mut_str data;            // Ponteiro para os dados  
    size_t length;           // Número de caracteres atuais  
    size_t capacity;         // Capacidade alocada  
    void (*string_from)(String *self, const str s); // Método para inicializar/atualizar  
} String;  
```
- Os campos capacity, data e o método de inicialização devem ser especificados, sendo length definido pelo próprio programa
---

## Exemplo
```
#include "strlib.h"  
#include <stdio.h>  

int main() {  
    // Cria uma string com capacidade inicial  
    String s = new_string(10);  

    // Inicializa com um literal  
    s.string_from(&s, "Olá");  

    // Concatena outra string  
    string_concat(&s, ", mundo!");  

    // Exibe resultado  
    printf("%s\n", s.data);  

    clean_str(); // Automaticamente limpa todas as Strings alocadas

    return 0;  
}  

Saída:  
Olá, mundo!  

---

## Compilação
### Linux
1. clone o repositório `git clone https://github.com/dvlPtrDev/strlib.git && cd strlib`
---
2. Gere a biblioteca `chmod +x gen_lib.sh && ./gen_lib.sh`
3. Chame a biblioteca no seu projeto com
```bash
  gcc <seu_projeto.c> \
  -I <path_para_strlib_include> \
  -L <path_para_strlib_out> \
  -l:libstr.a
```
4. (Opcional) coloque os arquivos no diretório /usr/local/include ou /usr/include para incluir a biblioteca usando #include <strlib.h> `sudo cp include/strlib.h /usr/local/include && sudo cp out/libstr.a /usr/local/lib`, então compile com `gcc <seu_projeto.c> -l:libstr.a

## 📌 Observações

- Limite atual: até **1024 strings** podem ser registradas simultaneamente.  
- Este projeto é voltado para aprendizado de **C e gerenciamento de memória**.  
- Inspirado em conceitos de **Rust** e **orientação a objetos em C**.  
- Futuras atualizações podem incluir:  
  - Suporte a **Unicode/UTF-8**  
  - Funções de busca e substituição  
  - Integração com testes automatizados (ex.: `CTest` ou `Unity`)  
  - Documentação em inglês para comunidade internacional  

---

## 📖 Licença

Este projeto é distribuído sob a licença MIT.  
Sinta-se livre para usar, modificar e compartilhar.  

---
