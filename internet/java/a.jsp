<%@ page import="java.util.Arrays" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册</title>
</head>
<body>
<%--编写 jsp 小脚本--%>
<%
    // getCookies()：获取请求发送时的Cookie对象的数组
    Cookie[] cookies = request.getCookies();
    // 定义变量用于value的显示
    String username = "", password = "";
    // 判断获取来的cookie是否为空，不为空执行
    if (cookies != null) {
        // 遍历cookie数组里的数据
        for (Cookie cookie : cookies) {
           /* System.out.println(cookie.getName());
            System.out.println(cookie.getValue());*/
            // getName()：获取Cookie名称(键)，等于前端传来的username的值
            if (cookie.getName().equals("username")) {
                // getValue()：获取Cookie的值，将值赋给变量username，用于后面value的显示
                username = cookie.getValue();
            }
            if (cookie.getName().equals("password")) {
                password = cookie.getValue();
            }
        }
    }
%>

<form action="registServlet" method="post">
                                                     <%-- =变量名：JSP中的语法，获取变量的值，显示到前端 --%>
    用户名：<input type="text" name="username" value="<%=username%>"> <br>
    密码：<input type="password" name="password" value="<%=password%>"> <br>
    <input type="submit" value="提交">
</form>
</body>
</html>
