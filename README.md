# 🔢 HexCalculator

> Conversor de decimal para hexadecimal feito com **C++** e **Assembly x86-64 (NASM)**

---

## 🛠️ Tecnologias

<p>
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/Assembly-6E4C13?style=for-the-badge&logo=assemblyscript&logoColor=white" alt="Assembly"/>
  <img src="https://img.shields.io/badge/NASM-darkred?style=for-the-badge&logoColor=white" alt="NASM"/>
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux"/>
</p>

---

## 📖 Descrição

**HexCalculator** é um projeto que demonstra a integração entre **C++** e **Assembly x86-64**. O núcleo da conversão é feito diretamente em Assembly NASM, usando operações de divisão (`div`) e registradores da CPU para calcular os dígitos hexadecimais de um número decimal informado pelo usuário.

O projeto explora:
- Convenção de chamadas **System V AMD64 ABI** (Linux x86-64)
- Uso de registradores `RAX`, `RDX`, `RCX`, `RDI`
- Comunicação entre **variáveis globais** C++ e Assembly via `extern "C"`
- Instrução `div` para divisão inteira e extração de restos

---

## 📂 Estrutura

```
HexCalculator/
├── main.cpp            # Interface C++, entrada/saída e lógica de letras hex
├── calculateHex.asm    # Núcleo da conversão em Assembly NASM
└── README.md
```

---

## ⚙️ Como compilar e rodar

### Requisitos
- `g++` (GCC)
- `nasm`

```bash
# Instalar NASM no Fedora
sudo dnf install nasm
```

### Compilar

```bash
# 1. Compilar o Assembly
nasm -f elf64 calculateHex.asm -o calc.o

# 2. Compilar e linkar com C++
g++ main.cpp calc.o -o Hexcalculator

# 3. Rodar
./Hexcalculator
```

### Ou tudo de uma vez

```bash
nasm -f elf64 calculateHex.asm -o calc.o && g++ main.cpp calc.o -o Hexcalculator && ./Hexcalculator
```

---

## 🧠 Como funciona

O Assembly recebe o número via registrador `RDI` (1º argumento, convenção Linux) e divide por 16 repetidamente, salvando os restos — que são os dígitos hexadecimais:

```
Exemplo: 255 ÷ 16 = 15 resto 15  →  FF em hex
```

O C++ então converte os restos `10~15` para as letras `A~F`.

---

## 📝 Exemplo de uso

```
Enter a decimal number to be converted to hexadecimal: 255

Resultado FF Hex
```

---
