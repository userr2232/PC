fun main() {
    readLine()
    var untreated = 0
    var free = 0
    readLine()!!.split(" ").map{ it.toInt() }.let {
        for (i in it.indices) {
            if(it[i] >= 1) free += it[i]
            else if(it[i] == -1 && free > 0) free--
            else untreated++
        }
    }
    println(untreated)
}