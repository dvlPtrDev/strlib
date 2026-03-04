# MyString Library

Biblioteca em **C** para manipulação de strings dinâmicas, oferece funcionalidades além das tradicionais `string.h`.  
Inclui gerenciamento centralizado de memória com registro de strings e liberação baseada em *memory pool*.  
Inspirada na forma como **Rust** lida com `String`.

---

## Funcionalidades

- Criação de strings dinâmicas com capacidade ajustável.  
- Inicialização e atualização de strings a partir de literais (`str`) ou outras strings.  
- Comparação de strings (`string_compare`).  
- Concatenação segura com ajuste automático de capacidade (`string_concat`).  
- Substituição de caracteres **in-place**.  
- Registro e rastreamento global de strings (`register_string`, `unregister_string`).  
- Função `clean_str` que libera todas as strings ao final do programa.  
- Reajuste automático de capacidade (`recalc_capacity`).  
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
  string.c        # Implementação das funções de string  
  memory.c        # Implementação de alocação  
  registry.c      # Registro global de strings  
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

## ⚙️ Compilação

1. clone o repositório `git clone https://github.com/dvlPtrDev/strlib.git`
---

## 🧪 Testes

Você pode criar um diretório `tests/` com programas simples para validar cada função:  

- Teste de criação e inicialização (`new_string`, `string_from`)  
- Teste de concatenação (`string_concat`)  
- Teste de comparação (`string_compare`)  
- Teste de limpeza (`drop_string`, `clean_str`)  

Exemplo de teste de comparação:  

String a = new_string(5);  
a.string_from(&a, "abc");  

String b = new_string(5);  
b.string_from(&b, "abc");  

printf("Comparação: %s\n", string_compare(a.data, b.data) ? "iguais" : "diferentes");  

---

## 📌 Observações

- Limite atual: até **1024 strings** podem ser registradas simultaneamente.  
- Este projeto é voltado para aprendizado de **C e gerenciamento de memória**.  
- Não substitui funções padrão da libc (`strlen`, `strcpy`, etc.), mas mostra como implementá-las manualmente.  
- Inspirado em conceitos de **Rust** e **orientação a objetos em C**.  
- Futuras melhorias podem incluir:  
  - Suporte a **Unicode/UTF-8**  
  - Funções de busca e substituição  
  - Integração com testes automatizados (ex.: `CTest` ou `Unity`)  
  - Documentação em inglês para comunidade internacional  

---

## 📖 Licença

Este projeto é distribuído sob a licença MIT.  
Sinta-se livre para usar, modificar e compartilhar.  

---

✍️ Autor: Pietro (16 anos, estudante)  
📅 Projeto criado para estudo e prática de programação em C.
