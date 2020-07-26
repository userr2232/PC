fun main() {
    var n = readLine()!!.toInt()
    var x = 0
    while(n-- > 0) {
        val s = readLine()!!.toCharArray().toSet()
        if(s.contains('+')) x++
        else x--
    }
    println(x)
}