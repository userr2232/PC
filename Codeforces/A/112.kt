fun main() {
    val x = readLine()!!.compareTo(readLine()!!, true)
    if(x > 0) println(1)
    else if(x < 0) println(-1)
    else println(0)
}