import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;

@WebServlet("/first")
public class FirstServlet extends HttpServlet {

    private static final Logger logger = LogManager.getLogger(FirstServlet.class);

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        logger.debug("Hello from Log4j 2");
        logger.debug("{}", 6);

        response.setContentType("text/html");

        response.getWriter().print("Test " + this.getClass().getName());
        processRequest(request, response);
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setAttribute("val", 4);
        request.getRequestDispatcher("/jsp/result.jsp").forward(request, response);
    }

    static int getNumber() {
        return 5;
    }
}
