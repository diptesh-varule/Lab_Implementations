$(document).ready(function () {
$("#submit").click(function () {
	$.post("/request",
		{
			name: "Megha",
			designation: "UG"
		},
		function (data, status) {
			console.log(data)
            // alert(data[0].name_recieved)
			localStorage.setItem("name","Megha")
			localStorage.setItem("designation","UG")
		});
});
});
