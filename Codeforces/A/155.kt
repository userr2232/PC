fun main() {
    readLine()!!
    var l = readLine()!!.split(" ").map{ it.toInt() }
    var min = l[0]
    var max = l[0]
    var count = 0
    for((i, x) in l.withIndex()) {
        if(i == 0) continue
        if(x > max) {
            max = x
            count++
        }
        else if(x < min) {
            min = x
            count++
        }
    }
    println(count)
}