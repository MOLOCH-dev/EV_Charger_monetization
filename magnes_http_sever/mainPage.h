const char MAIN_page[] PROGMEM = R"====(
    <!DOCTYPE html>
    <HTML>
    <HEAD>
    <TITLE>
    MAGNES MOTORS
    </TITLE>

    <script>
      function submitMessage(){
        alert("Your Watt Hour Input has been updated");
        
        setTimeout(function(){
        document.location.reload(false);
        },500);
        
        }

    </script>
    </HEAD>
    <BODY>
    <CENTER>
    <FORM method = "post" action = "/form">
    <TABLE>
    <TR><TD colspan=2><B>MONETIZING EV CHARGER PROJECT - DEMO</B></TD></TR>
    <!--
    <TR><TD>Your last input Watthours are : @@WATTHOUR@@</TD></TR>
    <TR><TD>Your estimated cost in Rupees is : @@COST@@</TD></TR>
    -->
    <TR><TD>
    ENTER REQUIRED WATT HOURS: 
    <INPUT TYPE =NUMBER name="required_watt_hour_value" value="100" id="user_input">
    <BR>
    <INPUT TYPE=SUBMIT VALUE="SUBMIT" onclick = submitMessage()> 
    </TD></TR>
    </TABLE>
    </FORM>
    </CENTER>
    </BODY>
    </HTML>
    )====";
