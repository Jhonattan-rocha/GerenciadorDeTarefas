import tkinter as tk
from tkinter import ttk


def remover_ultimo_grupo():
    filhos = frame_principal.winfo_children()
    if len(filhos) > 1:
        filhos[-1].destroy()


def adicionar_grupo():
    novo_grupo = tk.Frame(scrollable_frame)
    novo_grupo.pack(padx=5, pady=5)
    label = tk.Label(novo_grupo, text="Novo Grupo")
    label.pack()
    # Adicione aqui os campos e widgets que deseja para cada grupo


def on_configure(event):
    canvas.configure(scrollregion=canvas.bbox("all"))


root = tk.Tk()
root.title("Interface Dinâmica")

frame_superior = tk.Frame(root)
frame_superior.pack()

botao_adicionar = tk.Button(frame_superior, text="Adicionar Grupo", command=adicionar_grupo)
botao_adicionar.pack(side=tk.LEFT)

frame_principal = tk.Frame(root)
frame_principal.pack(fill=tk.BOTH, expand=True)

canvas = tk.Canvas(frame_principal)
scrollbar = ttk.Scrollbar(frame_principal, orient="vertical", command=canvas.yview)
scrollable_frame = tk.Frame(canvas)

canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
canvas.configure(yscrollcommand=scrollbar.set)
canvas.pack(side="left", fill="both", expand=True)
scrollbar.pack(side="right", fill="y")

adicionar_grupo()  # Adiciona um grupo inicial

# Configurar evento de redimensionamento da janela
root.bind("<Configure>", on_configure)

root.mainloop()
