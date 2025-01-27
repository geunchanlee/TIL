# Ollama 사용해보기

로컬에서 LLM을 사용해볼 수 있다.

Windows 11에서 진행했다.

## Ollama

### 설치

> https://ollama.com

### 모델 라이브러리

> https://ollama.com/library

### 모델 설치

llama3.2 설치
```
ollama run llama3.2
```

deepseek 설치

```
ollama run deepseek-r1:7b
```



## Python Libarary

> https://github.com/ollama/ollama-python

```
pip install ollama
```

### Chat 생성
```python
ollama.chat(model='llama3.2', messages=[{'role': 'user', 'content': 'Hi~~'}])
```
### List 보기
```python
ollama.list()
```

## 파이썬 코드를 사용해 실습 (deepseek-r1:7b)
### 응답 생성 함수 
```python
def generate_response(model, prompt):
    response = ollama.chat(model=model, messages=[{"role": "user", "content": prompt}])
    print(response["message"]["content"], end="\n\n")
```
### 결과
```
    Welcome to the new chat!
    To exit, Please type 'exit'.

>> Hi, how are you?
<think>

</think>

Hello! I'm just a virtual assistant, so I don't have feelings, but I'm here and ready to help you with whatever you need. How are *you* doing? 😊

>> exit
<think>

</think>

Goodbye! If you have any questions in the future, feel free to ask. 😊
```