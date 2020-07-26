fun main() {
    var (_ ,t) = readLine()!!.split(" ").map{ it.toInt() }
    var arr = readLine()!!.toCharArray()
    while(t-- > 0) {
        arr.let {
            var i = it.lastIndex
            while(i >= 1) {
                if(it[i] == 'G' && it[i - 1] == 'B') {
                    val tmp = it[i]
                    it[i] = it[i - 1]
                    it[i - 1] = tmp
                    i -= 2
                }
                else i--
            }
        }
    }
    println(arr.joinToString(""))
}