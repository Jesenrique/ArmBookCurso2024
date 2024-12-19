# Sistema de tratamiento de agua

**Informe de avance**

**Autor:** Jesús Enrique García Garnica

**Fecha:** 2° cuatrimeste del 2024

## Cumplimiento de los requerimientos

En base a los requerimientos planteados en la definición del proyecto, [requirements.md](https://github.com/Jesenrique/ArmBookCurso2024/blob/Jesenrique-patch-6/README.md), se evalúa el estado actual de cada uno indicando en verde aquellos que ya fueron cumplidos, en amarillo los que aún no fueron cumplidos pero se proyecta que será posible hacerlo, y en rojo los requerimientos que no serán cumplidos. El estado de los requerimientos se muestra en la tabla 1.

<h3>Significado de los colores:</h3>
<div style="display: flex; align-items: center; gap: 10px;">
  <div style="width: 20px; height: 20px; background-color: green; border-radius: 50%;"></div>
  <span>Cumplido</span>
</div>
<div style="display: flex; align-items: center; gap: 10px;">
  <div style="width: 20px; height: 20px; background-color: yellow; border-radius: 50%;"></div>
  <span>Pendiente, pero factible</span>
</div>
<div style="display: flex; align-items: center; gap: 10px;">
  <div style="width: 20px; height: 20px; background-color: red; border-radius: 50%;"></div>
  <span>Pendiente con dudas</span>
</div>

<table>
  <tr>
    <th>Categoría</th>
    <th>Req ID</th>
    <th>Descripción</th>
  </tr>
  <tr>
    <td rowspan="5">Firmware</td>
    <td>1.1</td>
    <td style="background-color: green;">Implementación de máquinas de estado para gestionar el sistema.</td>
  </tr>
  <tr>
    <td>1.2</td>
    <td style="background-color: green;">Control de interrupciones para control de nivel.</td>
  </tr>
  <tr>
    <td>1.3</td>
    <td style="background-color: green;">Comunicación UART para interacción con el menú del sistema.</td>
  </tr>
  <tr>
    <td>1.4</td>
    <td style="background-color: green;">Procesamiento de datos de sensores de presión y nivel.</td>
  </tr>
  <tr>
    <td>1.5</td>
    <td style="background-color: green;">Actualización periódica del LCD con el estado del sistema.</td>
  </tr>
  <tr>
    <td rowspan="3">Hardware</td>
    <td>2.1</td>
    <td style="background-color: green;">Integración de dos bombas y cuatro sensores de nivel.</td>
  </tr>
  <tr>
    <td>2.2</td>
    <td style="background-color: green;">Alimentación adecuada para todos los módulos.</td>
  </tr>
  <tr>
    <td>2.3</td>
    <td style="background-color: green;">Botón de emergencia conectado al sistema de control.</td>
  </tr>
  <tr>
    <td rowspan="2">Interfaz</td>
    <td>3.1</td>
    <td style="background-color: green;">Menú UART para configurar:<br>- Cambiar la frecuencia de la bomba de ósmosis.<br>- Verificar el estado del sistema.<br>- Detener el sistema completo.</td>
  </tr>
  <tr>
    <td>3.2</td>
    <td style="background-color: green;">LCD para mostrar las presiones, nivel del tanque y el estado de las bombas.</td>
  </tr>
<tr>
    <td rowspan="1">Seguridad</td>
    <td>4.1</td>
    <td style="background-color: green;">Implementación del botón de parada de emergencia para detener ambas bombas.</td>
  </tr>
</table>

**tabla 1**
