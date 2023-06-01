void right_y()
{
  Serial.println(server.arg("state_right_y"));
  String byf = server.arg("state_right_y");
  switch (byf.toInt()) {
    case 41: byfer_UART += "_SP1RY "; break;
    case 42: byfer_UART += "_SP2RY "; break;
    case 43: byfer_UART += "_SP3RY "; break;
    case 44: byfer_UART += "_SP4RY "; break;
    case 45: byfer_UART += "_SP5RY "; break;
    case 46: byfer_UART += "_SP6RY "; break;
    case 47: byfer_UART += "_SP7RY "; break;
    case 48: byfer_UART += "_SP8RY "; break;
    case 49: byfer_UART += "_SP9RY "; break;
    case 410: byfer_UART += "_SP10RY "; break;
    case 411: byfer_UART += "_SP11RY "; break;
    case 412: byfer_UART += "_SP12RY "; break;

    case -41: byfer_UART += "_SP1RYINV "; break;
    case -42: byfer_UART += "_SP2RYINV "; break;
    case -43: byfer_UART += "_SP3RYINV "; break;
    case -44: byfer_UART += "_SP4RYINV "; break;
    case -45: byfer_UART += "_SP5RYINV "; break;
    case -46: byfer_UART += "_SP6RYINV "; break;
    case -47: byfer_UART += "_SP7RYINV "; break;
    case -48: byfer_UART += "_SP8RYINV "; break;
    case -49: byfer_UART += "_SP9RYINV "; break;
    case -410: byfer_UART += "_SP10RYINV "; break;
    case -411: byfer_UART += "_SP11RYINV "; break;
    case -412: byfer_UART += "_SP12RYINV "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void right_x() {
  String byf = server.arg("state_right_x");
  switch (byf.toInt()) {
    case 31: byfer_UART += "_SP1RX "; break;
    case 32: byfer_UART += "_SP2RX "; break;
    case 33: byfer_UART += "_SP3RX "; break;
    case 34: byfer_UART += "_SP4RX "; break;
    case 35: byfer_UART += "_SP5RX "; break;
    case 36: byfer_UART += "_SP6RX "; break;
    case 37: byfer_UART += "_SP7RX "; break;
    case 38: byfer_UART += "_SP8RX "; break;
    case 39: byfer_UART += "_SP9RX "; break;
    case 310: byfer_UART += "_SP10RX "; break;
    case 311: byfer_UART += "_SP11RX "; break;
    case 312: byfer_UART += "_SP12RX "; break;

    case -31: byfer_UART += "_SP1RXINV "; break;
    case -32: byfer_UART += "_SP2RXINV "; break;
    case -33: byfer_UART += "_SP3RXINV "; break;
    case -34: byfer_UART += "_SP4RXINV "; break;
    case -35: byfer_UART += "_SP5RXINV "; break;
    case -36: byfer_UART += "_SP6RXINV "; break;
    case -37: byfer_UART += "_SP7RXINV "; break;
    case -38: byfer_UART += "_SP8RXINV "; break;
    case -39: byfer_UART += "_SP9RXINV "; break;
    case -310: byfer_UART += "_SP10RXINV "; break;
    case -311: byfer_UART += "_SP11RXINV "; break;
    case -312: byfer_UART += "_SP12RXINV "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void left_y()
{
  String byf = server.arg("state_left_y");
  switch (byf.toInt()) {
    case 21: byfer_UART += "_SP1LY "; break;
    case 22: byfer_UART += "_SP2LY "; break;
    case 23: byfer_UART += "_SP3LY "; break;
    case 24: byfer_UART += "_SP4LY "; break;
    case 25: byfer_UART += "_SP5LY "; break;
    case 26: byfer_UART += "_SP6LY "; break;
    case 27: byfer_UART += "_SP7LY "; break;
    case 28: byfer_UART += "_SP8LY "; break;
    case 29: byfer_UART += "_SP9LY "; break;
    case 210: byfer_UART += "_SP10LY "; break;
    case 211: byfer_UART += "_SP11LY "; break;
    case 212: byfer_UART += "_SP12LY "; break;

    case -21: byfer_UART += "_SP1LYINV "; break;
    case -22: byfer_UART += "_SP2LYINV "; break;
    case -23: byfer_UART += "_SP3LYINV "; break;
    case -24: byfer_UART += "_SP4LYINV "; break;
    case -25: byfer_UART += "_SP5LYINV "; break;
    case -26: byfer_UART += "_SP6LYINV "; break;
    case -27: byfer_UART += "_SP7LYINV "; break;
    case -28: byfer_UART += "_SP8LYINV "; break;
    case -29: byfer_UART += "_SP9LYINV "; break;
    case -210: byfer_UART += "_SP10LYINV "; break;
    case -211: byfer_UART += "_SP11LYINV "; break;
    case -212: byfer_UART += "_SP12LYINV "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
void left_x() {
  String byf = server.arg("state_left_x");
  switch (byf.toInt()) {
    case 11: byfer_UART += "_SP1LX "; break;
    case 12: byfer_UART += "_SP2LX "; break;
    case 13: byfer_UART += "_SP3LX "; break;
    case 14: byfer_UART += "_SP4LX "; break;
    case 15: byfer_UART += "_SP5LX "; break;
    case 16: byfer_UART += "_SP6LX "; break;
    case 17: byfer_UART += "_SP7LX "; break;
    case 18: byfer_UART += "_SP8LX "; break;
    case 19: byfer_UART += "_SP9LX "; break;
    case 110: byfer_UART += "_SP10LX "; break;
    case 111: byfer_UART += "_SP11LX "; break;
    case 112: byfer_UART += "_SP12LX "; break;

    case -11: byfer_UART += "_SP1LXINV "; break;
    case -12: byfer_UART += "_SP2LXINV "; break;
    case -13: byfer_UART += "_SP3LXINV "; break;
    case -14: byfer_UART += "_SP4LXINV "; break;
    case -15: byfer_UART += "_SP5LXINV "; break;
    case -16: byfer_UART += "_SP6LXINV "; break;
    case -17: byfer_UART += "_SP7LXINV "; break;
    case -18: byfer_UART += "_SP8LXINV "; break;
    case -19: byfer_UART += "_SP9LXINV "; break;
    case -110: byfer_UART += "_SP10LXINV "; break;
    case -111: byfer_UART += "_SP11LXINV "; break;
    case -112: byfer_UART += "_SP12LXINV "; break;

    default: break;
  }
  server.send(200, "text/plane", "OK");
}
