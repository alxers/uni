import org.apache.logging.log4j.Level;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.apache.logging.log4j.core.config.Configurator;

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
        //Configurator.setLevel("com.test2.FirstServlet", Level.INFO);
        Configurator.setRootLevel(Level.INFO);
        logger.info("The number provided is: " + request.getParameter("myVal"));

        response.setContentType("text/html");

        response.getWriter().print("The value was " + request.getParameter("myVal"));
        processRequest(request, response);
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int val = Integer.parseInt(request.getParameter("myVal"));
        request.setAttribute("myInputVal", val*val);
        request.getRequestDispatcher("/jsp/result.jsp").forward(request, response);
    }
}
