@WebServlet(name = "RegistServlet", value = "/registServlet")
public class RegistServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=UTF-8");

        // 获取前端传来的参数
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // 判断输入的账号和密码是否正确
        if (username.equals("root")  && password.equals("111")){
            // 创建Cookie对象，键值对形式存放
            Cookie cookie1 = new Cookie("username", username);
            Cookie cookie2 = new Cookie("password", password);
            // 设置cookie的存活时间
            cookie2.setMaxAge(10); // 以秒为单位，默认为-1永久存活(但是会在浏览器关闭时被删除)，0为删除
            // 在响应时添加cookie
            response.addCookie(cookie1);
            response.addCookie(cookie2);
        }

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
