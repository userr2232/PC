fun main () {
    var s = readLine()!!
    s = s.substring(1, s.length - 1)
    var st = s.split(", ").toMutableSet()
    if(!st.contains("")) println(st.size)
    else println(0)
}