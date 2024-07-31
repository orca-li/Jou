Ожидаемый результат:

jou.hook <br>
jou.tag <br>

jou.bin <br>

## channels and interfaces
```c
// interfaces
ifc_jt rs485;
ifc_jt usart;
// channels
jou_jt chj0;
jou_jt chj1;
// bind interfaces and channels
chj0.ifc = rs485;
chj1.ifc = usart;
```

## compare

jou.cmp
```
addr arr1       arr2
     hex ascii  hex ascii 
```

## dump register

Сделать структуру, потом в цикле выводить информацию о структуре
address, register name, full name <br>
register value <br>
flag - description <br>
flag - description <br>

## journal
```c
jou.init; // указать вершину журнала
jou.save; // записать в журнал
jou.load; // выгрузить журнал в массив
jou.read; // прочитать журнал
```

<h1>Completed </h1>

### stdio

jou.print <br>
jou.scan <br>
jou.getc <br>
jou.putc <br>

### logs

jou.err <br>
jou.wrn <br>
jou.dbg <br>
jou.inf <br>

### dumps

jou.hex <br>