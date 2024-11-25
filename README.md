## Definición de Requisitos y Casos de Uso del Trabajo Final introducción a Sistemas Embebidos  
#### Jesus Enrique Garcia Garnica 

#### 2do Cuatrimestre 2024  

# Sistema de tratamiento de agua  

## 1 - Marco del proyecto  

Para la elección del proyecto, se buscó implementar un sistema que combine sensores y actuadores comunes en sistemas industriales, promoviendo el aprendizaje de su funcionamiento y su integración para resolver problemas prácticos relacionados con el control de procesos.  

## 2 - Selección del proyecto a implementar  

En principio, se discutieron varios proyectos, eligiendo el sistema de control de agua debido a los siguientes criterios:  

- **Complejidad técnica**: Este proyecto combina el uso de sensores, actuadores y sistemas de control, representando un desafío adecuado para el tiempo de desarrollo estipulado.  
- **Disponibilidad del hardware**: Los módulos necesarios son accesibles y comunes en el mercado.  
- **Impacto educativo**: El proyecto proporciona experiencia práctica en sistemas embebidos, especialmente en el control de procesos industriales y diseño de interfaces.  

<table>
  <tr>
    <th>Proyecto</th>
    <th>Peso </th>
    <th>Tiempo de implementación (Peso: 8)</th>
    <th>Disponibilidad del Hardware (Peso: 3)</th>
    <th>Utilidad del proyecto (Peso: 9)</th>
    <th> Suma de puntajes pesados </th>
  </tr>
  <tr>
    <td rowspan="2">Sistema de tratamiento de agua</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">10</td>
    <td style="text-align: center;" rowspan="2">178</td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">64</td>
    <td style="text-align: center;">24</td>
    <td style="text-align: center;">90</td>
</tr>
<tr>
    <td rowspan="2">Alarma de seguridad</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">7</td>
    <td style="text-align: center;" rowspan="2"> 151 </td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">64</td>
    <td style="text-align: center;">24</td>
    <td style="text-align: center;">63</td>
    
</tr>
</table>

- Alarma de seguridad: se le asignó un puntaje de 8 en tiempo de implementación debido a que conlleva multiples sensores y su implementación es extensa. se asignó un 8 debido a que si bien no son muy comunes los modulos es necesario conseguir estos modulos en otras ciudades. Utilidad del proyecto se asignó un 7 si bien es un proyecto interesante y de gran utilidad en ambitos laborales ya hay un sistema implementado.

- Sistema de tratamiento de agua: se asignó un puntaje de 8 en tiempo de implementación debido a que su implementación es extensa. se asignó un 8 debido a que si bien no son muy comunes los modulos es necesario conseguir estos modulos en otras ciudades. Utilidad del proyecto se asignó un 10 debido a que por temas laborales puede funcionar como punto de partida para proyecto mas grande y mas estructurado

### 2.1 - Propósito del proyecto  

Diseñar un sistema de control de agua capaz de gestionar dos bombas y varios sensores para realizar un tratamiento de agua completo, con monitoreo y control en tiempo real. El sistema busca optimizar el consumo energético y garantizar la calidad del agua tratada.  

### 2.2 - Alcance del proyecto  

El sistema será desarrollado utilizando la placa **NUCLEO-144**, incluyendo las siguientes funcionalidades:  

1. Control de dos bombas mediante sensores de presión.  
2. Visualización del estado del sistema en un LCD.  
3. Interacción mediante un menú UART para ajustar parámetros y verificar el estado del sistema.  
4. Un botón de parada de emergencia que detiene las bombas inmediatamente.  

El sistema incluirá dos etapas principales:  

1. Pretratamiento del agua con filtros multimedia, suavizador y carbón activado.  
2. Ósmosis inversa para el tratamiento final del agua, con un tanque monitorizado por sensores de nivel.  

## 3 - Elicitación de Requisitos y Casos de Uso  

### 3.1 - Diagrama de bloques  

El siguiente diagrama de bloques representa las conexiones entre los componentes principales del sistema:  

*(Aquí se debe incluir un diagrama de bloques similar al del ejemplo, adaptado al sistema de control de agua).*

### 3.2 Análisis de mercado

Se analizan tres opciones de controladores para sistemas de tratamiento.

| Característica |  ROC-2015 | ROC-2315| ROC-8221|
|----------------|-----------------|---------|----------------------|
|Pantalla LED|No|No|Sí|
|Protección baja presión|Sí|Sí|Sí|
|Protección alta presión|Sí|Sí|Sí|
|Bomba de entrada|Sí|Sí|Sí|
|Bomba de alta presión|No|Sí|Sí|
|Nivel alto de tanque|Sí|Sí|Sí|
|Nivel medio de tanque|No|No|Sí|
|Nivel bajo de tanque|No|No|Sí|
|precio|107$|130$|300$|

Nota: Los precios se muestran en dolares y todos deben ser importados.

### 3.2 Requerimientos  

A continuación, se enumeran los requerimientos del sistema:  

#### **Firmware**  

| Req ID | Descripción |  
|--------|-------------|  
| 1.1    | Implementación de máquinas de estado para gestionar el sistema. |  
| 1.2    | Control de interrupciones para control de nivel. |  
| 1.3    | Comunicación UART para interacción con el menú del sistema. |  
| 1.4    | Procesamiento de datos de sensores de presión y nivel. |  
| 1.5    | Actualización periódica del LCD con el estado del sistema. |  

#### **Hardware**  

| Req ID | Descripción |  
|--------|-------------|  
| 2.1    | Integración de dos bombas y cuatro sensores de nivel. |  
| 2.2    | Alimentación adecuada para todos los módulos. |  
| 2.3    | Botón de emergencia conectado al sistema de control. |  

#### **Interfaz**  

| Req ID | Descripción |  
|--------|-------------|  
| 3.1    | Menú UART para:  
  - Cambiar la frecuencia de la bomba de ósmosis.  
  - Verificar el estado del sistema.  
  - Detener el sistema completo. |  
| 3.2    | LCD para mostrar las presiones, nivel del tanque el estado de las bombas. |  

#### **Seguridad**  

| Req ID | Descripción |  
|--------|-------------|  
| 4.1    | Implementación del botón de parada de emergencia para detener ambas bombas. |  

### 3.3 Casos de Uso  

A continuación, se detallan algunos casos de uso:  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | Presión por debajo del umbral mínimo. |  
| **Precondición**          | La bomba está activa. |  
| **Flujo básico**          | La bomba se detiene automáticamente para evitar daños. |  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | Se selecciona "Ver estado del sistema" en el menú UART. |  
| **Precondición**          | La conexión UART está establecida. |  
| **Flujo básico**          | Se muestra en el terminal el estado de las bombas y presiones. |  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | Se presiona el botón de emergencia. |  
| **Precondición**          | Una o ambas bombas están activas. |  
| **Flujo básico**          | Ambas bombas se detienen inmediatamente. |  

### Plazos  

| Fecha límite             | Entregable |  
|---------------------------|------------|  
| 30 de noviembre          | Informe de avance. |  
| 7 de diciembre           | Video demostrativo del sistema funcionando. |  
| 14 de diciembre          | Informe final del proyecto. |  
