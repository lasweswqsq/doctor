
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class DownloadServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 指定要下载的文件路径
        String downloadFile = "/path/to/your/file.txt";
        File file = new File(downloadFile);
        if (!file.exists()) {
            response.sendError(HttpServletResponse.SC_NOT_FOUND);
            return;
        }
        
        // 设置响应的Content-Type和Content-Disposition头信息
        String mimeType = getServletContext().getMimeType(file.getPath());
        if (mimeType == null) {
            mimeType = "application/octet-stream";
        }
        response.setContentType(mimeType);
        response.setContentLengthLong(file.length());
        String headerKey = "Content-Disposition";
        String headerValue = String.format("attachment; filename=\"%s\"", file.getName());
        response.setHeader(headerKey, headerValue);
        
        // 读取文件内容并写入到响应的输出流中
        try (FileInputStream inputStream = new FileInputStream(file)) {
            byte[] buffer = new byte[4096];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                response.getOutputStream().write(buffer, 0, bytesRead);
            }
        } catch (IOException e) {
            // 处理异常，‌例如记录日志或返回错误信息给用户等。‌
            e.printStackTrace(); // 在实际生产环境中，‌应使用更合适的错误处理机制。‌
        }
    }
}