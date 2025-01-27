import ollama


def generate_response(model, prompt):
    response = ollama.chat(model=model, messages=[{"role": "user", "content": prompt}])
    print(response["message"]["content"], end="\n\n")


print(
    """
    Welcome to the new chat!
    To exit, Please type 'exit'.
    """
)

model = "deepseek-r1:14b"

while True:
    prompt = input(">> ")
    if prompt == "exit":
        generate_response(model, "Goodbye!")
        exit()
    generate_response(model, prompt)
