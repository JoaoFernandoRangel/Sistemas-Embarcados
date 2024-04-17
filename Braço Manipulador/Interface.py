import tkinter as tk
from tkinter import messagebox
import serial
import random

Serial = 0
# Função para enviar os números pela porta serial
def enviar_numeros(num1, num2, num3, num4):
    if (Serial == 1):
        try:
            # Configuração da porta serial (ajuste de acordo com sua porta)
            ser = serial.Serial('COM3', 9600)  # Ajuste 'COM3' para sua porta e 9600 para sua baud rate
            
            # Envia os números pela porta serial
            ser.write(bytearray([num1 >> 8, num1 & 0xFF, num2 >> 8, num2 & 0xFF,
                                num3 >> 8, num3 & 0xFF, num4 >> 8, num4 & 0xFF]))
            
            ser.close()  # Fecha a porta serial
            
            messagebox.showinfo("Sucesso", "Números enviados com sucesso!")
        except serial.SerialException:
            messagebox.showerror("Erro", "Erro ao abrir a porta serial. Verifique as configurações.")
    else:
        print(num1,num2,num3,num4)

# Funções para enviar poses pré-definidas
pose1_values = [0, 0, 0, 0]
pose2_values = [0, 0, 0, 0]
pose3_values = [0, 0, 0, 0]

def enviar_pose1():
    enviar_numeros(int(pose1_values[0].get()), int(pose1_values[1].get()), int(pose1_values[2].get()), int(pose1_values[3].get()))

def enviar_pose2():
    enviar_numeros(int(pose2_values[0].get()), int(pose2_values[1].get()), int(pose2_values[2].get()), int(pose2_values[3].get()))

def enviar_pose3():
    enviar_numeros(int(pose3_values[0].get()), int(pose3_values[1].get()), int(pose3_values[2].get()), int(pose3_values[3].get()))

# Cria a janela principal
root = tk.Tk()
root.title("Envio de Números via Serial")

# Cria os campos de entrada para os números
label_num1 = tk.Label(root, text="Primeira Junta:")
label_num1.grid(row=0, column=0, padx=10, pady=5)
entry_num1 = tk.Entry(root)
entry_num1.grid(row=0, column=1, padx=10, pady=5)

label_num2 = tk.Label(root, text="Segunda Junta:")
label_num2.grid(row=1, column=0, padx=10, pady=5)
entry_num2 = tk.Entry(root)
entry_num2.grid(row=1, column=1, padx=10, pady=5)

label_num3 = tk.Label(root, text="Terceira Junta:")
label_num3.grid(row=2, column=0, padx=10, pady=5)
entry_num3 = tk.Entry(root)
entry_num3.grid(row=2, column=1, padx=10, pady=5)

label_num4 = tk.Label(root, text="Quarta Junta:")
label_num4.grid(row=3, column=0, padx=10, pady=5)
entry_num4 = tk.Entry(root)
entry_num4.grid(row=3, column=1, padx=10, pady=5)

# Botão para enviar os números
btn_enviar = tk.Button(root, text="Enviar", command=lambda: enviar_numeros(int(entry_num1.get()), int(entry_num2.get()), int(entry_num3.get()), int(entry_num4.get())))
btn_enviar.grid(row=4, column=0, columnspan=2, pady=10)

# Botões para envio das poses
btn_pose1 = tk.Button(root, text="Pose 1", command=enviar_pose1)
btn_pose1.grid(row=5, column=0, padx=5, pady=5)
pose1_values[0] = tk.Entry(root, width=10)
pose1_values[0].grid(row=5, column=1, padx=5, pady=5)
pose1_values[1] = tk.Entry(root, width=10)
pose1_values[1].grid(row=5, column=2, padx=5, pady=5)
pose1_values[2] = tk.Entry(root, width=10)
pose1_values[2].grid(row=5, column=3, padx=5, pady=5)
pose1_values[3] = tk.Entry(root, width=10)
pose1_values[3].grid(row=5, column=4, padx=5, pady=5)

btn_pose2 = tk.Button(root, text="Pose 2", command=enviar_pose2)
btn_pose2.grid(row=6, column=0, padx=5, pady=5)
pose2_values[0] = tk.Entry(root, width=10)
pose2_values[0].grid(row=6, column=1, padx=5, pady=5)
pose2_values[1] = tk.Entry(root, width=10)
pose2_values[1].grid(row=6, column=2, padx=5, pady=5)
pose2_values[2] = tk.Entry(root, width=10)
pose2_values[2].grid(row=6, column=3, padx=5, pady=5)
pose2_values[3] = tk.Entry(root, width=10)
pose2_values[3].grid(row=6, column=4, padx=5, pady=5)

btn_pose3 = tk.Button(root, text="Pose 3", command=enviar_pose3)
btn_pose3.grid(row=7, column=0, padx=5, pady=5)
pose3_values[0] = tk.Entry(root, width=10)
pose3_values[0].grid(row=7, column=1, padx=5, pady=5)
pose3_values[1] = tk.Entry(root, width=10)
pose3_values[1].grid(row=7, column=2, padx=5, pady=5)
pose3_values[2] = tk.Entry(root, width=10)
pose3_values[2].grid(row=7, column=3, padx=5, pady=5)
pose3_values[3] = tk.Entry(root, width=10)
pose3_values[3].grid(row=7, column=4, padx=5, pady=5)

root.mainloop()
