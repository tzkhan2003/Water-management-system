// comboBarLineChart
var ctx_combo_bar = document.getElementById("comboBarLineChart").getContext('2d');
var comboBarLineChart = new Chart(ctx_combo_bar, {
		type: 'bar',
		data: {
			labels: ["Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7"],
			datasets: [{
					type: 'bar',
					label: 'Profile-1',
					backgroundColor: '#6060C0',
					data: [173,167,143,153,148,156,187],
					borderColor: 'white',
					borderWidth: 0
				}, {
					type: 'bar',
					label: 'Profile-2',
					backgroundColor: '#2E856E',
					data: [172,182,153,162,151,161,178],
				},{
					type: 'bar',
					label: 'Profile-3',
					backgroundColor: '#63C5DA',
					data: [161,171,141,173,152,157,197],
					borderColor: 'white',
					borderWidth: 0
				},{
					type: 'bar',
					label: 'Profile-4',
					backgroundColor: '#FF6B8A',
					data: [193,168,142,157,147,154,171],
					borderColor: 'white',
					borderWidth: 0
				}], 
				borderWidth: 1
		},
		options: {
			scales: {
				yAxes: [{
					ticks: {
						beginAtZero:true
					}
				}]
			}
		}
});	


// barChart
var ctx_bar_chart = document.getElementById("barChart").getContext('2d');
var barChart = new Chart(ctx_bar_chart, {
		type: 'bar',
		data: {
			labels: ["Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7"],
			datasets: [{
				label: 'Litre(s)',
				data: [703,653,738,683,602,641,716],
				backgroundColor: [
					'rgba(255, 99, 132, 0.2)',
					'rgba(54, 162, 235, 0.2)',
					'rgba(255, 206, 86, 0.2)',
					'rgba(75, 192, 192, 0.2)',
					'rgba(153, 102, 255, 0.2)',
					'rgba(255, 159, 64, 0.2)',
					'rgba(255, 99, 132, 0.2)',
								
				],
				borderColor: [
					'rgba(255,99,132,1)',
					'rgba(54, 162, 235, 1)',
					'rgba(255, 206, 86, 1)',
					'rgba(75, 192, 192, 1)',
					'rgba(153, 102, 255, 1)',
					'rgba(255, 159, 64, 1)',
					'rgba(255,99,132,1)',
					
				],
				borderWidth: 1
			}]
		},
		options: {
			scales: {
				yAxes: [{
					ticks: {
						beginAtZero:true
					}
				}]
			}
		}
});
