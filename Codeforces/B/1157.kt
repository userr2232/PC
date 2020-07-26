fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    val fl = readLine()!!.split(" ").map{ it.toInt() }

    fun f(c: Char) = '0' + fl[c - '1']
    val i = s.indexOfFirst { c -> f(c) > c }
                .takeIf{ it >= 0 } ?: s.length
    val j = s.withIndex().indexOfFirst { (j, c) -> j > i && f(c) < c }
                .takeIf{ it >= 0 } ?: s.length
    val ans = 
            s.substring(0, i) + 
            s.substring(i, j).map{ c -> f(c) }.joinToString("") + 
            s.substring(j)

    println(ans)
}