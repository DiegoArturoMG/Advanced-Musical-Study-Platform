import filecmp, shutil, os

factor = 1000000

# A continuación, se realizan dos comparaciones superficiales
# y otras dos examinando el contenido; y se muestra el resultado

print(filecmp.cmp("arch1.txt", "arch2.txt", shallow=False))  # False
print(filecmp.cmp("arch1.txt", "arch3.txt", shallow=False))  # True

# Para trabajar con archivos pequeños y poder observar resultados
# "desconcertantes" asignar a la variable factor = 1 y ejecutar
# unas diez veces el código, observando sólo los resultados de la
# comparación. Es más que posible que el resultado de la primera
# comparación, a veces, sea True