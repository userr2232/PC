fun main() {
    val n = readLine()!!.toInt()
    for(i in 1..n) {
        val s = readLine()!!
        if(s.length <= 10)
            println(s)
        else
            println(s[0] + (s.length - 2).toString() + s[s.length - 1])
    }
}