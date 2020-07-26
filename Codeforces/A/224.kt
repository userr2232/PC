fun main() {
    val (ab, bc, ac) = readLine()!!.split(" ").map{ it.toInt() }
    var a: Int
    var b: Int
    var c: Int
    for(i in 1..10000) {
        if(ab % i == 0 && ac % i == 0 && (ab / i) * (ac / i) == bc) {
            a = i
            b = ab / a
            c = ac / a
            println(4 * (a + b + c))
            break
        }
    }
}