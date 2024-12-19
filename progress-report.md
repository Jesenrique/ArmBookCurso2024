# Sistema de tratamiento de agua

**Informe de avance**

**Autor:** Jesús Enrique García Garnica

**Fecha:** 2° cuatrimestre del 2024

## Cumplimiento de los requerimientos

En base a los requerimientos planteados en la definición del proyecto, [requirements.md](https://github.com/Jesenrique/ArmBookCurso2024/blob/Jesenrique-patch-6/README.md), se evalúa el estado actual de cada uno indicando:  
🟢 **Cumplido**  
🟡 **Pendiente, pero factible**  
🔴 **Pendiente con dudas**

El estado de los requerimientos se muestra en la tabla 1.

| **Categoría** | **Req ID** | **Descripción**                                                                                 | **Estado** |
|---------------|------------|-------------------------------------------------------------------------------------------------|------------|
| **Firmware**  | 1.1        | Implementación de máquinas de estado para gestionar el sistema.                                 | 🟢         |
|               | 1.2        | Control de interrupciones para control de nivel.                                                | 🟢         |
|               | 1.3        | Comunicación UART para interacción con el menú del sistema.                                     | 🟢         |
|               | 1.4        | Procesamiento de datos de sensores de presión y nivel.                                          | 🟢         |
|               | 1.5        | Actualización periódica del LCD con el estado del sistema.                                      | 🟢         |
| **Hardware**  | 2.1        | Integración de dos bombas y cuatro sensores de nivel.                                           | 🟢         |
|               | 2.2        | Alimentación adecuada para todos los módulos.                                                   | 🟢         |
|               | 2.3        | Botón de emergencia conectado al sistema de control.                                            | 🟢         |
| **Interfaz**  | 3.1        | Menú UART para configurar:  
|               |            | - Cambiar la frecuencia de la bomba de ósmosis.  | 🟢         |
|               |            | - Verificar el estado del sistema.  | 🟢         |
|               |            | - Detener el sistema completo.                                                                 | 🟢         |
|               | 3.2        | LCD para mostrar las presiones, nivel del tanque y el estado de las bombas.                     | 🟢         |
| **Seguridad** | 4.1        | Implementación del botón de parada de emergencia para detener ambas bombas.                     | 🟢         |

**Tabla 1**
