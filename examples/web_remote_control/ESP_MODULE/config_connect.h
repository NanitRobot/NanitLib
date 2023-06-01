void port_1()
{
  String byf = server.arg("state_port_1");
  switch (byf.toInt()) {
    case 1: byfer_UART += "_PORT1CONNECT "; break;
    case -1: byfer_UART += "_PORT1DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_2()
{
  String byf = server.arg("state_port_2");
  switch (byf.toInt()) {
    case 2: byfer_UART += "_PORT2CONNECT "; break;
    case -2: byfer_UART += "_PORT2DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_3()
{
  String byf = server.arg("state_port_3");
  switch (byf.toInt()) {
    case 3: byfer_UART += "_PORT3CONNECT "; break;
    case -3: byfer_UART += "_PORT3DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_4()
{
  String byf = server.arg("state_port_4");
  switch (byf.toInt()) {
    case 4: byfer_UART += "_PORT4CONNECT "; break;
    case -4: byfer_UART += "_PORT4DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_5()
{
  String byf = server.arg("state_port_5");
  switch (byf.toInt()) {
    case 5: byfer_UART += "_PORT5CONNECT "; break;
    case -5: byfer_UART += "_PORT5DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_6()
{
  String byf = server.arg("state_port_6");
  switch (byf.toInt()) {
    case 6: byfer_UART += "_PORT6CONNECT "; break;
    case -6: byfer_UART += "_PORT6DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_7()
{
  String byf = server.arg("state_port_7");
  switch (byf.toInt()) {
    case 7: byfer_UART += "_PORT7CONNECT "; break;
    case -7: byfer_UART += "_PORT7DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_8()
{
  String byf = server.arg("state_port_8");
  switch (byf.toInt()) {
    case 8: byfer_UART += "_PORT8CONNECT "; break;
    case -8: byfer_UART += "_PORT8DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_9()
{
  String byf = server.arg("state_port_9");
  switch (byf.toInt()) {
    case 9: byfer_UART += "_PORT9CONNECT "; break;
    case -9: byfer_UART += "_PORT9DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_10()
{
  String byf = server.arg("state_port_10");
  switch (byf.toInt()) {
    case 10: byfer_UART += "_PORT10CONNECT "; break;
    case -10: byfer_UART += "_PORT10DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_11()
{
  String byf = server.arg("state_port_11");
  switch (byf.toInt()) {
    case 11: byfer_UART += "_PORT11CONNECT "; break;
    case -11: byfer_UART += "_PORT11DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void port_12()
{
  String byf = server.arg("state_port_12");
  switch (byf.toInt()) {
    case 12: byfer_UART += "_PORT12CONNECT "; break;
    case -12: byfer_UART += "_PORT12DISCONNECT "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
