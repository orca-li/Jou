Ожидаемый результат:

jou.hook <br>
jou.tag <br>

jou.bin <br>
jou.dec <br>
jou.oct <br>

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

jou.comp
```
addr arr1 arr2 arr1   arr2   arr1 arr2
     hex  hex  ascii  ascii  dec  dec
```

## dump register

address, register name, full name <br>
register value <br>
flag - description <br>
flag - description <br>

## journal
```c
jou.j.init; // указать вершину журнала
jou.j.save; // записать в журнал
jou.j.load; // выгрузить журнал в массив
jou.j.read; // прочитать журнал
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