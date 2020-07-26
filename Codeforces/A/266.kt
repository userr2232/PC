fun main() {
    readLine()!!
    var count = 0
    readLine()!!.toCharArray().let {
        var cur = it[0]
        for((i, c) in it.withIndex()) {
            if(i == 0) {
                continue
            }
            if(c == cur)
                count++
            else
                cur = c
        }
    }
    println(count)
}